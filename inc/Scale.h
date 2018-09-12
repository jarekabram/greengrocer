#ifndef _SCALE_H_
#define _SCALE_H_

class Scale{
public:
	Scale();

	double getWeight() const { return m_weight; }
	void setWeight(double weight) { m_weight = weight; }

private:
	void init();
	double m_weight;
};

#endif
