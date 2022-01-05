

 
class cfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class digi_gasmaskFilter : ACE_ItemCore {
        scope = 2;
        author = "DiGii";
        displayName = "$STR_DIGI_Medical_GasFilterItem";
        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\DiGi_ACE_Extension_gas_more\addons\digi_main\ui\gasmaskfilter_ca";
        descriptionShort = "$STR_DIGI_Medical_GasFilterItem_desc";
        descriptionUse = "$STR_DIGI_Medical_GasFilterItem_desc";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class digi_Antidot : ACE_ItemCore {
        scope = 2;
        author = "DiGii";
        displayName = "$STR_DIGI_Medical_AntidotItem";
        model = "DiGi_ACE_Extension_gas_more\addons\digi_main\data\antidote.p3d";
        picture = "\DiGi_ACE_Extension_gas_more\addons\digi_main\ui\antidote_ca";
        descriptionShort = "$STR_DIGI_Medical_AntidotItem_desc";
        descriptionUse = "$STR_DIGI_Medical_AntidotItem_desc";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class digi_sealant : ACE_ItemCore {
        scope = 2;
        author = "DiGii";
        displayName = "$STR_DIGI_Medical_sealantItem";
        model = "\A3\Weapons_F\DummyItem.p3d";
        picture = "\DiGi_ACE_Extension_gas_more\addons\digi_main\ui\Sealant";
        descriptionShort = "$STR_DIGI_Medical_sealantItem_desc";
        descriptionUse = "$STR_DIGI_Medical_sealantItem_desc";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };

};