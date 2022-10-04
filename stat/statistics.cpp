#include <iostream>
#include <limits>
#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}
	virtual ~Min() = default;
	virtual void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}
	virtual ~Max() = default;
	virtual void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	virtual double eval() const override {
		return m_max;
	}

	virtual const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Arithmetic: public IStatistics{
public:
	Arithmetic(): m_mean{0}, m_number{0}{}
	virtual ~Arithmetic() = default;
	virtual void update(double next) override {

		m_mean=m_mean+next;
		m_number= m_number+1;
	}

	virtual double eval() const override{
		
		return m_mean/m_number;
	}

	virtual const char* name() const override{
		return "arithmetic mean";
	}

private:
	double m_mean;
	double m_number;

};

class Deviation : public IStatistics {
public:
	Deviation ():  m_number{0}, m_aver{0} {}
	virtual ~Deviation() = default;
	virtual void update(double next) override {
		m_mean.push_back(next);
		m_number = m_number +1;
		m_aver = m_aver + next;
		
	}

	virtual double eval() const override {
		double mean =0;
		for (size_t i=0; i<m_mean.size(); ++i){
			mean = mean+(m_mean[i]-m_aver/m_number)*(m_mean[i]-m_aver/m_number);
		}
		return sqrt(mean/m_number);
	}

	virtual const char* name() const override {
		return "standard deviation";
	}

private:
	std::vector<double> m_mean;
	double m_number;
	double m_aver;
};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Arithmetic{};
	statistics[3] = new Deviation{};
	
	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}