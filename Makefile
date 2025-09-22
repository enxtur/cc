# John Cricket's Coding Challenges
# Root Makefile to build and test all challenges

CHALLENGES_DIR = challenges
CHALLENGES = $(filter-out $(CHALLENGES_DIR)/template,$(wildcard $(CHALLENGES_DIR)/*))

.PHONY: all clean test $(CHALLENGES)

all: $(CHALLENGES)

# Build all challenges
$(CHALLENGES):
	@echo "Building $(notdir $@)..."
	@$(MAKE) -C $@

# Clean all challenges
clean:
	@echo "Cleaning all challenges..."
	@for challenge in $(CHALLENGES); do \
		if [ -f "$$challenge/Makefile" ]; then \
			echo "Cleaning $$challenge..."; \
			$(MAKE) -C $$challenge clean; \
		fi \
	done

# Test all challenges
test:
	@echo "Running tests for all challenges..."
	@./bin/test.sh

# Build specific challenge
build-%:
	@challenge=$(CHALLENGES_DIR)/$*; \
	if [ -d "$$challenge" ]; then \
		echo "Building $$challenge..."; \
		$(MAKE) -C $$challenge; \
	else \
		echo "Challenge $* not found in $(CHALLENGES_DIR)/"; \
		exit 1; \
	fi

# Clean specific challenge
clean-%:
	@challenge=$(CHALLENGES_DIR)/$*; \
	if [ -d "$$challenge" ]; then \
		echo "Cleaning $$challenge..."; \
		$(MAKE) -C $$challenge clean; \
	else \
		echo "Challenge $* not found in $(CHALLENGES_DIR)/"; \
		exit 1; \
	fi

# Test specific challenge
test-%:
	@challenge=$(CHALLENGES_DIR)/$*; \
	if [ -d "$$challenge" ]; then \
		echo "Testing $$challenge..."; \
		$(MAKE) -C $$challenge test; \
	else \
		echo "Challenge $* not found in $(CHALLENGES_DIR)/"; \
		exit 1; \
	fi

# List all available challenges
list:
	@echo "Available challenges:"
	@for challenge in $(CHALLENGES); do \
		echo "  - $$(basename $$challenge)"; \
	done

# Create a new challenge from template
new-%:
	@echo "Creating new challenge: $*"
	@./bin/new-challenge.sh $*