@MAXN = 505
@INF = 9999999

n = gets.to_i

m = Array.new(@MAXN+1) { Array.new(@MAXN+1) }

for i in 0..@MAXN
	for j in 0..@MAXN
		if i != j
			m[i][j] = @INF
		else 
			m[i][j] = 0
		end
	end
end

arr = Array.new(n){ Array.new() }

maxVal = 1

for i in 0..n-1
	s = gets
	s.split(" ").each { |e|
		arr[i] << e.to_i
	}
	a = arr[i][0]
	b = arr[i][1]
	c = arr[i][2]
	maxVal = [ maxVal , a , b ].max
	m[a][b] = [ m[a][b] , c ].min
	m[b][a] = [ m[b][a] , c ].min
end

for k in 0..maxVal
	for i in 0..maxVal
		for j in 0..maxVal
			m[i][j] = [ m[i][j] , m[i][k] + m[k][j] ].min
		end
	end
end

u = gets.to_i
q = gets.to_i

for i in 0..q-1
	v = gets.to_i
	ans = [ m[u][v] , m[v][u] ].min
	if ans == @INF 
		puts "NO PATH"
	else
		puts ans
	end
end
