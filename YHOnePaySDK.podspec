
Pod::Spec.new do |s|

  s.name         = "YHOnePaySDK"
  s.version      = "1.5.18"
  s.summary      = "统一支付SDK"

  s.description  = "统一支付SDK，封装了支付宝支付、微信支付、银联支付、支付宝Wap支付、微信Wap支付等多种支付方式。对接指南：https://showdoc.ylzpay.com/web/#/page/1161 "

  s.homepage     = "https://github.com/XmYlzYhkj/YHOnePaySDK"

  s.license      = "MIT"

  s.author       = { "XmYhkj" => "yhkj_xm@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/XmYlzYhkj/YHOnePaySDK.git", :tag => s.version.to_s }

  s.frameworks       = 'SystemConfiguration', 'CoreMotion','CFNetwork', 'CoreTelephony', 'QuartzCore', 'CoreText', 'CoreGraphics', 'UIKit', 'Foundation', 'WebKit'

  s.libraries        = 'z', 'c++', 'sqlite3'

  s.requires_arc = true

  s.default_subspecs = 'Default'

  s.resources = 'Resources/*.bundle'
      
  s.user_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => '$(EXCLUDED_ARCHS__EFFECTIVE_PLATFORM_SUFFIX_$(EFFECTIVE_PLATFORM_SUFFIX)__NATIVE_ARCH_64_BIT_$(NATIVE_ARCH_64_BIT)__XCODE_$(XCODE_VERSION_MAJOR))',
    'EXCLUDED_ARCHS__EFFECTIVE_PLATFORM_SUFFIX_simulator__NATIVE_ARCH_64_BIT_x86_64__XCODE_1200' => 'arm64 arm64e armv7 armv7s armv6 armv8'
  }

  s.dependency     'YHBaseSDK'
  s.dependency     'YHCategorySDK'
  s.dependency     'YHUtiliitiesSDK'
  s.dependency     'YHAlertSDK'
   
  s.subspec 'Default' do |sp|

      #包含：支付宝、微信
      sp.vendored_frameworks = ["Frameworks/AliWx/*.framework"]
      sp.dependency 'AlipaySDK-iOS'
      sp.dependency 'WechatOpenSDK'
      
  end
  

  s.subspec 'AliWxUnion' do |sp|

      #包含：支付宝、微信、银联支付
      sp.vendored_frameworks = ["Frameworks/AliWxUnion/*.framework"]
      sp.dependency 'AlipaySDK-iOS'
      sp.dependency 'WechatOpenSDK'
      sp.dependency 'YHUPPayPluginSDK'

  end
  

  s.subspec 'AliWxUMS' do |sp|

      #包含：支付宝、微信、银联支付新版
      sp.vendored_frameworks = ["Frameworks/AliWxUMS/*.framework"]
      sp.dependency 'AlipaySDK-iOS'
      sp.dependency 'WechatOpenSDK'
      sp.dependency 'YHUMSPosPayOnly'

  end
  

  s.subspec 'Alipay' do |sp|

      #包含：支付宝
      sp.vendored_frameworks = ["Frameworks/Alipay/*.framework"]
      sp.dependency 'AlipaySDK-iOS'

  end
  

  s.subspec 'Wxpay' do |sp|

      #包含：微信
      sp.vendored_frameworks = ["Frameworks/Wxpay/*.framework"]
      sp.dependency 'WechatOpenSDK'

  end
  

  s.subspec 'All' do |sp|      
      #包含：支付宝、微信、银联支付、银联支付新版
      sp.vendored_frameworks = ["Frameworks/All/*.framework"]
      sp.dependency 'AlipaySDK-iOS'
      sp.dependency 'WechatOpenSDK'
      sp.dependency 'YHUPPayPluginSDK'
      sp.dependency 'YHUMSPosPayOnly'
  end



end
