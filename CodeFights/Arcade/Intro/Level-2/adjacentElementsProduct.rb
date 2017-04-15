def adjacentElementsProduct(array)
	max_product = array[0] * array[1]
	a = 1
	b = 2
	
	while b < array.count do
		product = array[a] * array[b]
		if product > max_product then
			max_product = product
		end
		a += 1
		b += 1
	end
	return max_product
end
