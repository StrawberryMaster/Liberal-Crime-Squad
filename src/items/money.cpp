#include "../includes.h"
const string CONST_money003 = "$";
const string CONST_money002 = "amount";

const string tag_money = "money";
#include "../creature/creatureEnums.h"
#include "../items/itemtype.h"
#include "../items/item.h"
#include "../items/money.h"
//own header


Money::Money(const std::string& inputXml) : Item(inputXml)
{
	CMarkup xml;
	xml.SetDoc(inputXml);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem()) if (xml.GetTagName() == CONST_money002) amount_ = atoi(xml.GetData().c_str());
}
string Money::showXml() const
{
	CMarkup xml;
	xml.AddElem(tag_money);
	xml.IntoElem();
	addBaseValues(xml);
	xml.AddElem(CONST_money002, tostring(amount_));
	return xml.GetDoc();
}
Money* Money::split(int number)
{
	flatten();
	if (number > amount_) number = amount_;
	Money* newi = clone();
	newi->amount_ = number;
	amount_ -= number;
	return newi;
}
bool Money::merge(Item& i)
{
	flatten();
	if (i.whatIsThis() == THIS_IS_MONEY && is_same_type(i))
	{
		Money& m = static_cast<Money&>(i); //cast -XML
		m.flatten();
		take_all_from(m);
		m.set_number(0);
		return true;
	}
	else return false;
}
bool Money::sort_compare_special(Item* other) const
{
	return other && !(other->whatIsThis() == THIS_IS_MONEY);
}
string Money::equip_title() const
{
	return CONST_money003 + tostring(amount_);
}