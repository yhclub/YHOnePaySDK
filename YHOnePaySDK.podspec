
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
   
  s.subspec 'Default' do |defsub|

      defsub.vendored_frameworks = ["Frameworks/AliWxUnion/*.framework"]

  end
  

  s.subspec 'AliWxUnion' do |awu|

      awu.vendored_frameworks = ["Frameworks/AliWxUnion/*.framework"]

  end
  

  s.subspec 'AliWx' do |aliwx|

      aliwx.vendored_frameworks = ["Frameworks/AliWx/*.framework"]

  end
  
#  s.subspec 'All' do |all|
#      
#      all.vendored_frameworks = ["Frameworks/All/*.framework"]
#  end



end
