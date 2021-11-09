#!/bin/bash


data()
{
	perl <<'EOF'
my $n = 10;
my $l = 10;
my $s = 64;

print("$n $l $s\n");
for (1 .. $n / 2) {
	my $str = "";
	$str .= chr(rand(26) + ord('a')) for (1 .. $l);
	my @arr = split('', $str);

	my $pos = rand(@arr - 1) + 1;
	my $npos = rand($pos);

	my $chr = chr(rand(26) + ord('a'));
	$chr = chr(rand(26) + ord('a')) while ($chr eq $arr[$pos]);

	my $nchr = chr(rand(26) + ord('a'));
	$nchr = chr(rand(26) + ord('a')) while ($nchr eq $arr[$npos]);

	print("$str\n");

	$arr[$pos] = $chr;
	if (rand() < 0.5) {
		print("@{[join('', @arr)]}\n");
	} else {
		$arr[$npos] = $nchr;
		print("@{[join('', @arr)]}\n");
	}
}
EOF
}

comp()
{
	gcc std.c -o std && gcc main.c -o main
}

comp || exit 1

for i in {1..100}; do
	echo $i
	data > in
	./main < in > out
	./std < in > ans
	diff out ans || exit 1
done

rm -f in out ans std main
