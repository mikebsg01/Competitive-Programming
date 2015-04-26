n = gets.to_i

for i in 0..n-1
	s = gets
	tmp = s.split(" ")
	a = tmp[0].to_i
	b = tmp[1].to_i
	puts "#{a*b}"
end