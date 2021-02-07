for f in ./data/*.hl7;
do
	echo -n -e "\x0b$(cat hl7v2-mllp-sample.txt)\x1c\x0d" | nc -C -q 5 10.128.0.15 2575 >> "../MLLP Solace App/data/${f::-3}.mllp"
done