Pod::Spec.new do |s|
    s.name             = "ShopcorePay"   
    s.version          = "1.0.0"    
    s.summary          = "shop pay"  
    s.description  = "Easily integrate a shop"
    s.homepage         = "https://www.shop2cn.cn"
    s.license          = "MIT"        
    s.author             = { "sunny" => "18763895318@163.com" }                   
    s.source       = { :git => "https://github.com/xuzheng94/SQShopcorePay.git", :tag => s.version }                          
    s.frameworks = "UIKit"
    s.vendored_frameworks = "shopcore.xcframework"
    s.dependency "Shopcore-Cordova-iOS", '~>1.3.10'
    s.requires_arc = true
    s.ios.deployment_target = "10.0"
    s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end