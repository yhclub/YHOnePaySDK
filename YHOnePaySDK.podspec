
Pod::Spec.new do |s|

  s.name         = "YHOnePaySDK"
  s.version      = "1.4.0"
  s.summary      = "统一支付SDK"

  s.description  = "统一支付SDK，封装了支付宝支付、微信支付、银联支付、支付宝Wap支付、微信Wap支付等多种支付方式。对接指南：http://120.42.37.94:9999/showdoc-master/web/#/page/1161 "

  s.homepage     = "https://github.com/XmYlzYhkj/YHOnePaySDK"

  s.license      = "MIT"

  s.author       = { "XmYhkj" => "yhkj_xm@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/XmYlzYhkj/YHOnePaySDK.git", :tag => s.version.to_s }

  s.frameworks       = 'SystemConfiguration', 'CoreMotion','CFNetwork', 'CoreTelephony', 'QuartzCore', 'CoreText', 'CoreGraphics', 'UIKit', 'Foundation', 'WebKit'

  s.libraries        = 'z', 'c++', 'sqlite3'

  s.dependency 'YHBaseSDK',         '~> 1.1'
  s.dependency 'YHCategorySDK',     '~> 1.0'
  s.dependency 'YHUtiliitiesSDK',   '~> 1.0'
  s.dependency 'YHAlertSDK',        '~> 1.0'
  s.dependency 'SAMKeychain',       '~> 1.5'

  s.requires_arc = true

  s.vendored_frameworks = ["Frameworks/*.framework"]

  s.resources    = 'Resources/*.bundle'

  s.default_subspecs = 'Alipay', 'Wxpay', 'Unionpay'

  s.subspec 'Alipay' do |alipay|

      alipay.dependency 'YHAlipaySDK',       '~> 15.5'
  end
  
  s.subspec 'Wxpay' do |wxpay|

      wxpay.dependency 'YHWechatSDK',       '~> 1.8'
  end
  
  s.subspec 'Unionpay' do |up|

      up.dependency 'YHUPPayPluginSDK',  '~> 0.1'
  end
  

end
