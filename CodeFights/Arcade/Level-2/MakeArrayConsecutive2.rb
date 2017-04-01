def makeArrayConsecutive2(statues)
	minSize = statues.min
	maxSize = statues.max
	(maxSize - minSize + 1) - statues.count
end
