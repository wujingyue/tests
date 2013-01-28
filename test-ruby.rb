#!/usr/bin/ruby

class Dog
	attr_reader \
		:age, :name

	def initialize(name, age = 0)
		@name = name
		@age = age
	end
end
