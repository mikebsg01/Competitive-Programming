def invertParentheses c
	if c == '(' then ')'
	elsif c == ')' then '('
	else c
	end
end

def reverseSubarray s, a, b
	while a < b
		s[a], s[b] = s[b], s[a]
		s[a] = invertParentheses(s[a])
		s[b] = invertParentheses(s[b])
		a += 1
		b -= 1
	end
end

def reverseInParentheses s
	stack = []
	s.chars.each_index {|i|
		if s[i] == '('
			stack << i
		elsif s[i] == ')'
			reverseSubarray(s, stack.pop + 1, i - 1)
		end
	}
	return s.delete '()'
end

require_relative '../../../../Tools/tester.rb'
require 'test/unit/assertions'

class Tests
	include Test::Unit::Assertions

	def test_case_1
		input = "foo(bar(baz))blim"
		output = reverseInParentheses(input)
		expected_output = "foobazrabblim"

		assert output === expected_output,
			"Expected: '#{expected_output}' Got: '#{output}'"
	end

	def test_case_2
		input = "(ed(et(oc))el)"
		output = reverseInParentheses(input)
		expected_output = "leetcode"

		assert output === expected_output,
			"Expected: '#{expected_output}' Got: '#{output}'"
	end

	def test_case_3
		input = "a(bcdefghijkl(mno)p)q"
		output = reverseInParentheses(input)
		expected_output = "apmnolkjihgfedcbq"

		assert output === expected_output,
			"Expected: '#{expected_output}' Got: '#{output}'"
	end
end

Tester.new Tests