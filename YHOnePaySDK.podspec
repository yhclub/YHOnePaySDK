
Pod::Spec.new do |s|

  s.name         = "YHOnePaySDK"
  s.version      = "1.0.0"
  s.summary      = "统一支付SDK"

  s.description  = "统一支付SDK，封装了支付宝支付、微信支付、银联支付、支付宝Wap支付、微信Wap支付等多种支付方式。"

  s.homepage     = "https://github.com/XmYlzYhkj/YHOnePaySDK"

  s.license      = "MIT"

  s.author       = { "XmYhkj" => "yhkj_xm@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/XmYlzYhkj/YHOnePaySDK.git", :tag => "1.0.0" }

  #s.source_files  = "Classes", "Classes/*", "Resources", "Resources/*"

  s.requires_arc = true

  s.vendored_frameworks = ["Classes/YHOnePaySDK.framework"]
  
end
