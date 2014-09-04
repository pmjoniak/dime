#include <iostream>
#include "dime/Input.h"
#include "dime/sections/Section.h"
#include "dime/Model.h"
#include "dime/entities/Polyline.h"
#include "dime/entities/LWPolyline.h"
#include "dime/convert/convert.h"
#include "dime/sections/EntitiesSection.h"
#include "dime/entities/Circle.h"
#include "dime/entities/FaceEntity.h"
#include "dime/entities/Solid.h"

int main()
{
	dimeInput in;
	in.setFile("zmorphlogo.dxf");

	dimeModel model;

	if (!model.read(&in)) {
		fprintf(stderr, "DXF read error in line: %d\n", in.getFilePosition());
		return -1;
	}
	dimeEntitiesSection *es = (dimeEntitiesSection*)model.findSection("ENTITIES");
	for (int i = 0; i < es->getNumEntities(); i++)
	{
		auto enti = es->getEntity(i);
		int type = enti->typeId();
		if (type == dimeBase::dimeLWPolylineType)
		{
			auto poli = dynamic_cast<dimeLWPolyline*>(es->getEntity(i));
			std::cout << poli;
		}
		else if (type == dimeBase::dimePolylineType)
		{
			auto poli = dynamic_cast<dimePolyline*>(es->getEntity(i));
			std::cout << poli;
		}
	}
}