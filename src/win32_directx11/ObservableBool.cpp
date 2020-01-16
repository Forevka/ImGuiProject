#include <vector>
#include <iostream>

class ObserverABC {
public:
	virtual void trigger() = 0;
};

class MyObserver : public ObserverABC {
public:
	virtual void trigger()
	{
		std::cout << "test" << std::endl;
	};
};

class TestObserver : public ObserverABC {
public:
	virtual void trigger()
	{
		std::cout << "test123" << std::endl;
	};
};

class ObservableBool {
private:
	bool value = true;
	std::vector<ObserverABC*> observers_ = std::vector<ObserverABC*>();

public:
	bool getValue() {
		return value;
	}

	bool setValue(bool value) {
		bool changed = (value != this->value);
		this->value = value;
		if (changed) raiseEvent();

		return true;
	}

	void addObserver(ObserverABC* observer) {
		observers_.push_back(observer);
	}

	void removeObserver(ObserverABC* observer) {
		auto a = std::find(observers_.begin(), observers_.end(), observer);
		observers_.erase(a);
	}

private:
	void raiseEvent() {
		for (int i = 0; i < observers_.size(); ++i) {
			observers_[i]->trigger();
		}
	}
};

/*int main()
{
	ObservableBool* test = new ObservableBool();
	test->addObserver(new MyObserver());
	test->addObserver(new TestObserver());

	test->setValue(false);
}*/