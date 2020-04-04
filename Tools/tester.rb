class Tester
	def initialize(tests_class)
		tests = tests_class.new

		tests.public_methods(false).each do |test_case|
			test_case_name = test_case
				.to_s
				.gsub('_', ' ')
				.capitalize

			print "#{test_case_name}: "

			begin
				tests.send(test_case)
				print "AC"
			rescue Exception => ex
				puts "WA"
				puts "#{ex.message}"
			end

			puts
		end
	end
end