require 'matrix'

def constructSubmatrix(matrix, rowsToDelete, columnsToDelete)
	rows = matrix.size - rowsToDelete.size
    	columns = matrix[0].size - columnsToDelete.size
    	m = Array.new(rows) { Array.new(columns, 0) }
	k = l = 0

    	matrix.each_with_index { |v,i|
        	matrix[i].each_with_index { |w,j|
            		unless rowsToDelete.include? i or columnsToDelete.include? j then
				m[k][l] = matrix[i][j]
				l += 1

				k = (l == columns) ? k + 1 : k
				l = (l == columns) ? 0 : l
            		end
		}
	}
	return m
end


matrix = [[1, 0, 0, 2], 
          [0, 5, 0, 1], 
          [0, 0, 3, 5]]

rowsToDelete = [1]

columnsToDelete = [0, 2]

sm = constructSubmatrix(matrix, rowsToDelete, columnsToDelete)

puts sm.inspect

# Solved in: 21.22 m 
# Expected: 15 m
