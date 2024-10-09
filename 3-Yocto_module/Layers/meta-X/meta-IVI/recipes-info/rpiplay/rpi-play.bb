# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# WARNING: the following LICENSE and LIC_FILES_CHKSUM values are best guesses - it is
# your responsibility to verify that the values are complete and correct.
#
# The following license files were not able to be identified and are
# represented as "Unknown" below, you will need to check them yourself:
#   LICENSE
#   lib/llhttp/LICENSE-MIT
#   lib/playfair/LICENSE.md
LICENSE = "Unknown"
LIC_FILES_CHKSUM = "file://LICENSE;md5=1ebbd3e34237af26da5dc08a4e440464 \
                    file://lib/llhttp/LICENSE-MIT;md5=f5e274d60596dd59be0a1d1b19af7978 \
                    file://lib/playfair/LICENSE.md;md5=c7cd308b6eee08392fda2faed557d79a"

SRC_URI = "git://github.com/FD-/RPiPlay.git;protocol=https;branch=master"

# Modify these as desired
PV = "1.0+git${SRCPV}"
SRCREV = "64d0341ed3bef098c940c9ed0675948870a271f9"

S = "${WORKDIR}/git"

# NOTE: the following library dependencies are unknown, ignoring: brcmEGL openmaxil brcmGLESv2 plist bcm_host vcos plist-2 vchiq_arm
#       (this is based on recipes that have previously been built and packaged)
DEPENDS = "openssl avahi libplist libsdl2 libconfig" 


inherit cmake pkgconfig

 
# Specify any options you want to pass to cmake using EXTRA_OECMAKE:
EXTRA_OECMAKE = ""

