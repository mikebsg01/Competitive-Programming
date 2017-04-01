def shapeArea(n)
	# Initial Formula 	= ((2 * n - 1) * (2 * n)) / 2 - (n - 1)
	# Clearing 		= (((4 * n * n) - (2 * n)) / 2) - n + 1
	# ...      		= (4 * n * n) / 2 - n - n + 1
	# ...      		= (2 * n * n) - (2 * n) + 1
	# Final Formula 	= (2 * n) * (n - 1) + 1
	(2 * n) * (n - 1) + 1
end
