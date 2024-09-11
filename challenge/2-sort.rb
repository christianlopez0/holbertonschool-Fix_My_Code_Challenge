#!/usr/bin/ruby
# Sort integer arguments (ascending)

result = []

ARGV.each do |arg|
    # Skip if not an integer
    next unless arg =~ /^-?\d+$/

    # Convert to integer
    i_arg = arg.to_i

    # Insert the integer in the correct position to keep the list sorted
    index = result.bsearch_index { |x| x >= i_arg } || result.size
    result.insert(index, i_arg)
end

puts result
