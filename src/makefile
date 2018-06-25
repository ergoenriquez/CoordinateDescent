RM := rm

# All Target
all: CoordinateDescent

# Tool invocations
CoordinateDescent:
	@echo 'Building target: $@'
	g++ -I "Eigen/" -O2 -DNDEBUG "test_cd.cpp" "cd.cpp" -o CoordinateDescent --verbose
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CoordinateDescent
	-@echo ' '
