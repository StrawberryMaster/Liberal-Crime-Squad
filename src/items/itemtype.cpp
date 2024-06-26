

#include "../includes32.h"
#include "../constStringitemtype.h"
int ItemType::number_of_itemtypes = 0;
ItemType::ItemType(MCD_STR xmlstring)
	: name_(CONST_UNDEFINED), name_future_defined_(false), fencevalue_(0)
{
	init(xmlstring);
}
ItemType::ItemType(const ItemType& base, MCD_STR xmlstring)
{
	idname_ = base.idname_;
	id_ = base.id_;
	name_ = base.name_;
	name_future_ = base.name_future_;
	name_future_defined_ = base.name_future_defined_;
	fencevalue_ = base.fencevalue_;
	init(xmlstring);
}
void ItemType::init(const MCD_STR& xmlstring)
{
	id_ = number_of_itemtypes++;
	CMarkup xml;
	xml.SetDoc(xmlstring);
	xml.FindElem();
	idname_ = xml.GetAttrib(tag_idname);
	if (!len(idname_))
		idname_ = CONST_LACKS_IDNAME + tostring(id_);
	xml.IntoElem();
	while (xml.FindElem()) //Loop over all the elements inside the element.
	{
		std::string element = xml.GetTagName();
		if (element == tag_name)
			name_ = xml.GetData();
		else if (element == tag_name_future)
		{
			name_future_ = xml.GetData();
			name_future_defined_ = true;
		}
		else if (element == tag_fencevalue)
			fencevalue_ = atoi(xml.GetData().c_str());
		/*else
		errorlog << CONST_UNKNOWN_ELEMENT_FOR_ITEM_TYPE_IDNAME: " << element << endl;*/
	}
}
const string& ItemType::get_name() const
{
	if (name_future_defined_ && year >= 2100)
		return name_future_;
	else
		return name_;
}