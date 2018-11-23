def almostIncreasingSequence(a)
  pos = 0
  d = (0...a.size-1).count { |i|
    if a[i] >= a[i+1]
      pos = i
    end
  }
  return false if d > 1
  return true if d == 0 || a.size == 2 || pos == 0 ||
                (pos != 0 and (
                  (a[pos-1] < a[pos] and pos == (a.size-2)) ||
                  a[pos-1] < a[pos+1] ||
                  ((pos + 2) < a.size and a[pos] < a[pos+2] and a[pos] > a[pos-1])
                ))
  return false
end

# puts almostIncreasingSequence([1,2,1,2])
