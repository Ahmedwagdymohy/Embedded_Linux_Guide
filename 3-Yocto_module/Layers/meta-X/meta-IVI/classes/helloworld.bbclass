do_install () {
	# 1. Create dir ${workdir}/image/usr/bin
	install -d ${D}/${bindir}
	# 2. installing hello bin --> dir ${workdir}/image/usr/bin
	install -m 0755 ${S}/hello ${D}/${bindir}
}




# ignore the do_package_qa
do_package_qa[noexec] = "1"