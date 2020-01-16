#include <vector>
#include <iostream>

class TriggerABC {
public:
	virtual ~TriggerABC() = default;
	virtual void Trigger() = 0;
};

class MyTrigger final : public TriggerABC {
public:
	void Trigger() override
	{
		std::cout << "test" << std::endl;
	};
};

class TestTrigger final : public TriggerABC {
public:
	void Trigger() override
	{
		std::cout << "test123" << std::endl;
	};
};

class TriggerComponent {
	std::vector<TriggerABC*> triggers_ = std::vector<TriggerABC*>();

public:
	void AddTrigger(TriggerABC* observer) {
		triggers_.push_back(observer);
	}

	void RemoveTrigger(TriggerABC* observer) {
		triggers_.erase(std::find(triggers_.begin(), triggers_.end(), observer));
	}

	void RaiseEvent() {
		for (auto& trigger : triggers_)
		{
			trigger->Trigger();
		}
	}
};