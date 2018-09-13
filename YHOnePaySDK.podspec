
Pod::Spec.new do |s|

  s.name         = "YHOnePaySDK"
  s.version      = "1.2.1.12"
  s.summary      = "统一支付SDK"

  s.description  = "统一支付SDK，封装了支付宝支付、微信支付、银联支付、支付宝Wap支付、微信Wap支付等多种支付方式。对接指南：http://120.42.37.94:9999/showdoc-master/web/#/page/1161 "

  s.homepage     = "https://github.com/XmYlzYhkj/YHOnePaySDK"

  s.license      = "MIT"

  s.author       = { "XmYhkj" => "yhkj_xm@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/XmYlzYhkj/YHOnePaySDK.git", :tag => s.version.to_s }

  s.frameworks       = 'SystemConfiguration', 'CoreMotion','CFNetwork', 'CoreTelephony', 'QuartzCore', 'CoreText', 'CoreGraphics', 'UIKit', 'Foundation', 'WebKit'

  s.libraries        = 'z', 'c++', 'sqlite3'

  s.dependency     'YHBaseSDK'##, '1.1.2'

  s.dependency     'YHCategorySDK'##, '1.0.1'

  s.dependency     'YHUtiliitiesSDK'##, '1.0.1'

  s.dependency     'YHAlertSDK'##, '1.0.0'

  s.dependency     'YHWechatSDK'##, '1.8.2'

  s.dependency     'YHAlipaySDK'##, '15.5.2'

  s.dependency     'SVProgressHUD', '~> 2.1.2'

  s.dependency     'SAMKeychain', '~> 1.5.2'

  s.dependency	   'YHUPPayPluginSDK', '~> 0.1.4'

  s.requires_arc = true

  s.vendored_frameworks = ["Frameworks/*.framework"]

  s.resources    = 'Resources/*.bundle'


end
