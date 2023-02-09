//
//  XtionAIShareManager.h
//  XtionAISDK
//
//  Created by Howell-Ye on 2019/10/28.
//  Copyright © 2019 xtion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Photos/Photos.h>


NS_ASSUME_NONNULL_BEGIN


//图片检测类型
typedef NS_ENUM(NSUInteger,XtionAIDetectType)
{
    XtionAIDetectTypeShelf = 0,
    XtionAIDetectTypeFreezer = 1,
    XtionAIDetectTypeWaterHeap,
};

//请求成功回调block
typedef void (^xtionAISuccessBlock)(NSDictionary *dic);

//请求失败回调block
typedef void (^xtionAIFailureBlock)(NSError *error);

@interface XtionAIShareManager : NSObject

@property (nonatomic,copy) NSString *authToken;

@property (nonatomic,copy) NSString *requestHost;
@property (nonatomic,copy) NSString *sdkH5Host;
@property (nonatomic,copy) NSString *sdkH5Token;
@property (nonatomic,copy) NSDictionary *upaccount;

@property (nonatomic, copy) NSString *account;

@property (nonatomic, copy) NSString *accessKey;

+(instancetype)sharedManager;

- (BOOL)iSAuthTokenValid;



//旧版初始化
- (void)SDKHost:(NSString *)account accessKey:(NSString *)accessKey  result:(void(^) (NSDictionary *dict))result;
- (void)checkWebFilesVersionWithsdkH5Host:(NSString *)sdkH5Host sdkH5Token:(NSString *)sdkH5Token;
//获取全景相机图片
- (void)getFullSencePictures:(NSArray *)cameraModeArr flashMode:(NSString *)flashMode type:(NSString *)type showPreview:(BOOL)showPreview dataRetained:(NSString *)dataRetained quality:(int)quality quantity:(int)quantity recTime:(int)recTime videoQuality:(int)videoQuality result:(void(^) (NSDictionary *dict,BOOL isFinished))result;

- (void)getFakePhotos:(NSArray *)paths result:(void(^) (NSDictionary *dict))result;

//获取单张照片
- (void)getPictureWithRedBox:(BOOL)isRedBox cameraObliqueType:(NSInteger)cameraObliqueType  result:(void(^) (UIImage *image,NSArray *redBoxPoints))result;

- (void)getPictureWithRedBox:(BOOL)isRedBox cameraObliqueType:(NSInteger)cameraObliqueType aiCompress:(NSInteger)aiCompress  result:(void(^) (UIImage *image,NSArray *redBoxPoints))result;

//获取拼接照片
- (void)getSplicingPictures:(void(^) (NSArray<UIImage *> *images))result;

//混合相机 默认带拼接
- (void)getSmartPictures:(void(^) (NSArray<UIImage *> *images,BOOL isSplicing))result;

- (void)getSmartPicturesCameraOpenType:(NSInteger)cameraOpenType cameraObliqueType:(NSInteger)cameraObliqueType blurryCheck:(BOOL)blurryCheck obliqueCheck:(BOOL)obliqueCheck maxSingleCount:(NSInteger)maxSingleCount maxMultCount:(NSInteger)maxMultCount coverRange:(double)coverRange  result:(void(^) (NSArray<UIImage *> *images,BOOL isSplicing))result;

//相册选择相片
-(void)getselectPhoto:(void(^) (NSString *photoPath,UIImage *image))result;
-(void)getselectVideo:(void(^) (NSString *videoPath,UIImage *image,BOOL isFinined))result;
-(void)getVideoFirstFrameWithVideoPath:(NSString *)videoPath result:(void(^) (UIImage *image))picresult;
-(void)getVideoAllFrameWithVideoPath:(NSString *)videoPath result:(void(^) (NSArray * images))picresult;

//系统相机拍照
-(void)getAIPhoto:(void(^) (NSString *photoPath,UIImage *image))result;

//获取视频默认事件为30s
- (void)getAIVideo:(void(^) (NSString *videoPath,UIImage *image,BOOL isFinined))result;

//可拍摄时长为10-120s
- (void)getAIVideoBySecond:(NSInteger)second result:(void(^) (NSString *videoPath,UIImage *image,BOOL isFinined))result;

//获取边缘计算结果
-(void)getAIDetectPhoto:(NSString *)ImagePath detectType:(int)detectType reslut:(void(^) (NSDictionary *dict))result;
//获取视频拼接链接
-(void)getVideoSpliceImageByVideoPath:(NSString *)videoPath reslut:(void(^) (NSString * videoImagePath,int status))result;
//旧版翻拍识别
- (void)SDKFakePhoto:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版识别
- (void)SDKDectect:(NSString *)imageUrl priceDetect:(NSString *)priceDetect detectType:(XtionAIDetectType)type success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

- (void)SDKAsyncDectect:(NSArray <NSString *> *)imageUrls priceDetect:(NSString *)priceDetect detectType:(XtionAIDetectType)type success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版拼接
- (void)SDKMergePhoto:(NSArray<NSString *> *)imageUrls priceDetect:(NSString *)priceDetect success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版视频识别
- (void)SDKVideoDectect:(NSString *)videoUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版获取识别结果
- (void)SDKGetDetectResult:(NSString *)identityId batchId:(NSString *)batchId success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版获取视频识别结果
- (void)SDKGetVideoDetectResult:(NSString *)videoId success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//旧版拼接结果
- (void)SDKGetMergeResult:(NSString *)identityId success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//获取价签识别结果
- (void)SDKGetPriceResult:(NSString *)identityId priceType:(NSString *)priceType success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//端架识别
- (void)detectShelfSKU:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//冰柜识别
- (void)detectFreezerSKU:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//水箱SKU识别
- (void)detectWaterHeapSKU:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//获取SKU识别结果
- (void)getSkuResult:(NSString *)identityId success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//SDK展示SKU识别结果
- (void)showSKUView:(NSString *)title skuResult:(NSString *)detectResult result:(void(^) (NSDictionary *dict))result;

//店头OCR识别
- (void)detectStorePicture:(NSString *)imageUrl storeName:(NSString *)storeName Points:(NSArray *)points success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//本地店头识别
- (void)detectLocalStorePicture:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//防翻拍
- (void)fakePicture:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//场景识别
- (void)placeDetect:(NSString *)imageUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//拼接
- (void)mergePhoto:(NSArray<NSString *> *)imageUrls success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//拼接结果
- (void)getMergeResult:(NSString *)identityId success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//判重
- (void)compare:(NSArray *)imageUrls With:(NSString *)baseUrl success:(xtionAISuccessBlock)success failure:(xtionAIFailureBlock)failure;

//视频压缩
- (void)compressedVideo:(NSString *)videoPath videoQuality:(NSInteger)videoQuality result:(void(^) (NSString *videoPath,NSString *error))result;

- (void)compressedVideo:(NSString *)videoPath toFilepath:(NSString *)filePath videoQuality:(NSInteger)videoQuality result:(void(^) (NSString *videoPath,NSString *error))result;

//播放视频
- (void)playVideo:(NSString *)videoPath;

//压缩图片大小
- (UIImage *)resizeImageWithImage:(UIImage *)image targetSize:(CGSize)targetSize;

- (void)compressedImageFiles:(UIImage *)image imageKB:(CGFloat)fImageKBytes imageBlock:(void(^)(NSData *imageData))block;

- (void)resetSizeOfImageFiles:(UIImage *)image imageKB:(CGFloat)fImageKBytes imageBlock:(void(^)(NSData *imageData))block;

+ (void)getCameraAuthAlertShow:(BOOL)show success:(void (^)(void))success fail:(void (^)(AVAuthorizationStatus authStatus))fail;

+ (void)getAudioAuthAlertShow:(BOOL)show success:(void (^)(void))success fail:(void (^)(AVAuthorizationStatus authStatus))fail;

+ (void)getAlbumAuthAlertShow:(BOOL)show success:(void (^)(void))success fail:(void (^)(PHAuthorizationStatus authStatus))fail;

- (void)showImagePreview:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
