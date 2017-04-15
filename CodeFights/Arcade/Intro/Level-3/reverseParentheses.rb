def isParenthesis?(c)
  c == '(' or c == ')'
end

def __reverseParentheses s, r
  ans = ""
  a = s.chars
  i = 0
  while i < a.size
    unless isParenthesis?(a[i])
      ans << a[i]
      i += 1
    else
      j = i + 1
      p_open = 1
      while j < a.size and p_open > 0
        if isParenthesis?(a[j])
          p_open += a[j] == '(' ? 1 : -1
        end
        j += 1
      end
      ans += __reverseParentheses(s[i+1, j-i-2], true)
      i = j
    end
  end
  return r ? ans.reverse : ans
end

def reverseParentheses s
  __reverseParentheses(s, false)
end

# puts reverseParentheses("ab(ac((op)(ab)ty))"), reverseParentheses("a(bc)de")

=begin
  ab(ac((op)(ab)ty))
  ab(ac(pobaty))
  ab(acytabop)
  Answer: abpobatyca

  a(bc)de
  Answer: acbde
=end
