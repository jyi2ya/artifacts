#!/usr/bin/perl

$/ = undef;
my $code = <>;

# 去掉注释
$code =~ s/#.*?\n/\n/gs;

# 去掉 vars 标签
$code =~ s/{[^}]*vars.*?}//gs;

# 处理 yosoro
$code =~ s/:yosoro(.*?)\n/print $1\nprint ' '\n/gs;

# 处理 set
$code =~ s/:set(.*?),(.*?)\n/$1 = $2\n/g;

# 转换逻辑操作符
$code =~ s/([^a-z])lt([^a-z])/$1<$2/gs;
$code =~ s/([^a-z])gt([^a-z])/$1>$2/gs;
$code =~ s/([^a-z])le([^a-z])/$1<=$2/gs;
$code =~ s/([^a-z])ge([^a-z])/$1>=$2/gs;
$code =~ s/([^a-z])eq([^a-z])/$1==$2/gs;
$code =~ s/([^a-z])neq([^a-z])/$1!=$2/gs;

# 代码块嵌套
while ($code =~ m/ihu/ or $code =~ m/hor/ or $code =~ /while/) {
	$code =~ s/\{[^\{\}]*?ihu([^,\{\}]*),([^,\{\}]*),([^,\{\}\n]*)\n([^\}\{]*?)\}/IF ($2 $1 $3) <%\n $4 %>\n/gs;
	$code =~ s/\{[^\{\}]*?hor([^,\{\}]*),([^,\{\}]*),([^,\{\}\n]*)\n([^\}\{]*?)\}/FOR $1 ( $2 .. $3 ) <%\n $4 %>\n/gs;
	$code =~ s/\{[^\{\}]*?while([^,\{\}]*),([^,\{\}]*),([^,\{\}\n]*)\n([^\}\{]*?)\}/WHILE ($2 $1 $3) <%\n $4 %>\n/gs;
}

$code =~ s/<%/{/g;
$code =~ s/%>/}/g;

# 保护关键字
for my $keyword (qw/print/) {
	$code =~ s/([^a-z])${keyword}([^a-z])/$1\U$keyword\E$2/gs;
}

# 给变量加上魔法
$code =~ s/([^a-z\$])([a-z])/$1\$$2/gs;

# 给数字加上魔法
$code =~ s/([^0-9\'])([0-9]+)/$1'$2'/gs;

# 转回关键字
for my $keyword (qw/if for while print while if for/) {
	$code =~ s/([^a-z])\U$keyword\E([^a-z])/$1$keyword$2/gs;
}

# 使用哈希，防止数组越界
$code =~ s/\[/{/gs;
$code =~ s/\]/}/gs;

# 加上分号
$code =~ s/\n/;\n/gs;

# --L-i-v-e--（bushi） 运行！
eval $code;
