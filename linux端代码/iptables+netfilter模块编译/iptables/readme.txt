注意：使用Ubuntu12.04
iptable使用1.4.12来编译
才能成功
解压后，将libxt_modbusTcp.c拷贝到extention目录下，退出extention目录后先configure再make（产生错误不用管，只要生成了需要的so文件就行）,生成libxt_modbusTcp.so文件拷贝到/lib/xtables目录下。netfilter目录下make 后将生成的xtmodbusTcp.ko插入内核即可