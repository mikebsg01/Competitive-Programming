def reverseParentheses(s)
  stack = []
  word = ''
  s.chars.each do |c|
    if c == '('
      stack.push word
      word = ''
    elsif c == ')'
      word = stack.pop + word.reverse
    else
      word += c
    end
  end
  word
end

# puts reverseParentheses("ab(ac((op)(ab)ty))"), reverseParentheses("a(bc)de")
