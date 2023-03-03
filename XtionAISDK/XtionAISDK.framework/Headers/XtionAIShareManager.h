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
//- (void)getFullSencePictures:(NSArray *)cameraModeArr flashMode:(NSString *)flashMode type:(NSString *)type showPreview:(BOOL)showPreview dataRetained:(NSString *)dataRetained quality:(int)quality quantity:(int)quantity recTime:(int)recTime videoQuality:(int)videoQuality result:(void(^) (NSDictionary *dict,BOOL isFinished))result;
- (void)getFullSencePictures:(NSArray *)cameraModeArr  dataRetained:(NSString *)dataRetained result:(void(^) (NSDictionary *dict,BOOL isFinished))result;

- (void)getFakePhotos:(NSArray *)paths result:(void(^) (NSDictionary *dict))result;

@end

NS_ASSUME_NONNULL_END
