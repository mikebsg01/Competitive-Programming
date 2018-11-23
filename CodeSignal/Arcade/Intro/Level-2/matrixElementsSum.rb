def matrixElementsSum m
  ans = 0
  (0...m[0].size).each{|j|
    isSuitable = true
    x = (0...m.size).each{|i|
      isSuitable = isSuitable && m[i][j] != 0
      ans += isSuitable ? m[i][j] : 0
    }
  }
  return ans
end

=begin
puts matrixElementsSum([
  [0, 1, 1, 2],
  [0, 5, 0, 0],
  [2, 0, 3, 3]
])
=end
