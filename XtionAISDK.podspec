#
# Be sure to run `pod lib lint XtionAISDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'XtionAISDK'
  s.version          = '0.1.7'
  s.summary          = 'A short description of XtionAISDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/lookyouforever/XtionAISDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'engune' => 'tjb0931@gmail.com' }
  s.source           = { :git => 'https://github.com/lookyouforever/XtionAISDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'
  s.platform     = :ios, '11.0'
  s.requires_arc = true

  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

  s.vendored_frameworks = 'XtionAISDK/*.{framework}'
  s.resources  = "XtionAISDK/*.{bundle}"
  s.dependency 'OpenCV2', '~> 4.3.0'
  
  # s.source_files  = "XtionAISDK/*.{h,m}"

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
