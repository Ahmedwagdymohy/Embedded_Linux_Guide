# We will follow the following stes 
# 1. include the base image
# 2. Setting some local variables
# 3. IMAGE_INSTALL & IMAGE_FEATURES 




# we will take the base image as the raspberrypi image

require recipes-core/images/rpi-test-image.bb






# 2. Setting some local variables
SUMMARY = "IVI Testing Image that includes the rpi image + helloworld package we have created"




# 3. IMAGE_INSTALL & IMAGE_FEATURES
IMAGE_INSTALL:append = " helloworld nano"
IMAGE_FEATURES:append = " debug-tweaks"
