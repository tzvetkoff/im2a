require 'formula'

class Im2a < Formula
  homepage 'https://github.com/tzvetkoff/im2a'
  url 'git://github.com/tzvetkoff/im2a.git'
  version '0.1.1'

  depends_on 'imagemagick'

  def install
    ENV.prepend_path 'PATH', '/usr/local/bin'
    system 'make'
    bin.install ['im2a']
  end
end
