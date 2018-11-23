def newRoadSystem(m)
	a = Array.new(m.size) { 0 }
	b = Array.new(m.size) { 0 }
	for i in 0...m.size
		for j in 0...m[i].size
			if m[i][j]
				a[i] += 1
			end
			if m[j][i]
				b[i] += 1
			end
		end
	end
	# puts a.inspect
	# puts b.inspect
	for i in 0...m.size
		if a[i] != b[i]
			return false
		end
	end
	true
end

def main()
	roadRegister = [[false, true,  false, false, false, false, false],
	                [true,  false, false, false, false, false, false],
	                [false, false, false, true,  false, false, false],
		        [false, false, true,  false, false, false, false],
		        [false, false, false, false, false, false, true ],
		        [false, false, false, false, true,  false, false],
		        [false, false, false, false, false, true,  false]]
	puts newRoadSystem(roadRegister).inspect
end

if __FILE__ == $0
	main()
end
