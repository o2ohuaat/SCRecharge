#
#  Be sure to run `pod spec lint SCRecharge.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "SCRecharge"
  s.version      = "1.0.3"
  s.summary      = "o2ohuaat oil card recharge sdk."

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description  = <<-DESC
  SCRecharge cocoapods integration
                   DESC

  s.homepage     = "https://github.com/o2ohuaat/SCRecharge"
  # s.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"

  s.license      = { :type => "Apache License, Version 2.0", :file => "LICENSE" }

  s.author             = { "o2ohuaat" => "o2o@yiliangche.net" }

  s.platform     = :ios

  s.ios.deployment_target = "7.0"

  s.source       = { :git => "https://github.com/o2ohuaat/SCRecharge.git", :tag => "#{s.version}" }

  s.requires_arc = true
  
  s.vendored_frameworks = 'SCRecharge.framework'
  
  s.frameworks = 'JavaScriptCore','SystemConfiguration', 'Security', 'UIKit', 'Foundation', 'CFNetwork'

end
