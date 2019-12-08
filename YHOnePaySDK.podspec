
Pod::Spec.new do |s|

  s.name         = "YHOnePaySDK"
  s.version      = "1.5.3"
  s.summary      = "统一支付SDK"

  s.description  = "统一支付SDK，封装了支付宝支付、微信支付、银联支付、支付宝Wap支付、微信Wap支付等多种支付方式。对接指南：http://120.42.37.94:9999/showdoc-master/web/#/page/1161 "

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
      
  s.dependency     'YHBaseSDK'
  s.dependency     'YHCategorySDK'
  s.dependency     'YHUtiliitiesSDK'
  s.dependency     'YHAlertSDK'
   
  s.subspec 'Default' do |dt|

      dt.summary = "包含：支付宝、微信、银联支付"
      dt.vendored_frameworks = ["Frameworks/AliWxUnion/*.framework"]
      dt.dependency 'YHAlipaySDK'
      dt.dependency 'YHWechatSDK'
      dt.dependency 'YHUPPayPluginSDK'
      
  end
  

  s.subspec 'AliWxUnion' do |awu|

      awu.summary = "包含：支付宝、微信、银联支付"
      awu.vendored_frameworks = ["Frameworks/AliWxUnion/*.framework"]
      awu.dependency 'YHAlipaySDK'
      awu.dependency 'YHWechatSDK'
      awu.dependency 'YHUPPayPluginSDK'

  end
  

  s.subspec 'AliWx' do |aliwx|

      aliwx.summary = "包含：支付宝、微信"
      aliwx.vendored_frameworks = ["Frameworks/AliWx/*.framework"]
      aliwx.dependency 'YHAlipaySDK'
      aliwx.dependency 'YHWechatSDK'

  end
  
  s.subspec 'All' do |all|
      
      all.summary = "包含：支付宝、微信、银联支付"
      all.vendored_frameworks = ["Frameworks/All/*.framework"]
      all.dependency 'YHAlipaySDK'
      all.dependency 'YHWechatSDK'
      all.dependency 'YHUPPayPluginSDK'
  end



end
