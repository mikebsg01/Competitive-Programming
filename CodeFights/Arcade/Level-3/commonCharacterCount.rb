def commonCharacterCount a, b
  a = a.chars
  b.chars.count{|c| if a.include?(c) then a.delete_at(a.find_index(c)) end }
end

# puts commonCharacterCount("aabcc", "adcaa")
