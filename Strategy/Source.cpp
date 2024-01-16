#include <iostream>
using namespace std;

class RouteStrategy abstract
{
public:
	virtual void buildRoute() abstract;
};

class RoadStrategy: public RouteStrategy
{
public:
	void buildRoute() override {
		cout << "Route was constructed for roads." << endl;
	}
};

class WalkingStrategy: public RouteStrategy
{
public:
	void buildRoute() override {
		cout << "Route was constructed for hikers." << endl;
	}
};

class PublicTransportStrategy: public RouteStrategy
{
public:
	void buildRoute() override {
		cout << "Route was constructed for public transport." << endl;
	}
};

class Navigator
{
	RouteStrategy* route_strategy;

public:
	void buildRoute() {
		route_strategy->buildRoute();
	}
	void SetRouteStrategy(RouteStrategy* route_strategy)
	{
		this->route_strategy = route_strategy;
	}
};

int main()
{
	Navigator route;

	RoadStrategy roadStrategy;
	route.SetRouteStrategy(&roadStrategy);
	route.buildRoute();

	WalkingStrategy walkingStrategy;
	route.SetRouteStrategy(&walkingStrategy);
	route.buildRoute();

	PublicTransportStrategy publicStrategy;
	route.SetRouteStrategy(&publicStrategy);
	route.buildRoute();

	system("pause");
	return 0;
}
	
