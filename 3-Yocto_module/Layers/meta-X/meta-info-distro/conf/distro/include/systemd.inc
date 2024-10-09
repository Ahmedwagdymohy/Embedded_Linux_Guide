# install systemd service  as init manager



DISTRO_FEATURES:append = " systemd"


# Add systemd as init manager
VIRTUAL-RUNTIME_init_manager = "systemd"

VIRTUAL-RUNTIME_initscripts = "systemd-compat-units"

