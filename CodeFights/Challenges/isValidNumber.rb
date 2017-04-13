require 'scanf'

def isValidNumber s,n,c,d
  /^#{'-?' if n}(\d#{'\d?(,\d{3})*|\d' if c}+)#{'(\.\d+)?' if d}$/ === s
end

=begin
print "Negative (y/n): "
N = scanf("%c")[0] == 'y' ? true : false
print "Commas (y/n): "
C = scanf("%c")[0] == 'y' ? true : false
print "Decimal (y/n): "
D = scanf("%c")[0] == 'y' ? true : false
print "String: "
S = scanf("%s")[0]
puts [S, N, C, D].inspect
puts isValidNumber(S, N, C, D)
=end
