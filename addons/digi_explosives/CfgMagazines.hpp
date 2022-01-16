class CfgMagazines {

	class APERSTripMine_Wire_Mag;
	class DIGI_Gas_TripWireMine_Mag: APERSTripMine_Wire_Mag {
		author = "DiGii";
		ammo = "DIGI_Gas_TripWireMine_Ammo";
		ace_explosives_SetupObject = "ACE_Explosives_Place_APERSTripwireMine";
		displayName = "$STR_DIGI_Explosives_TriWire_Gas_Name";
		descriptionShort = "$STR_DIGI_Explosives_TriWire_Gas_Desc";
		class Library {libTextDesc = "$STR_DIGI_Explosives_TriWire_Gas_Desc";};
	};

	class Default;	// External class reference
	class VehicleMagazine;
	class PylonMissile_Bomb_GBU12_x1;
	class PylonRack_Bomb_GBU12_x2;
	class DIGI_CAS_M43_Mag: PylonMissile_Bomb_GBU12_x1 {

		ammo = "DIGI_CAS_M43_Ammo";
		author = "DiGii";
		count = 1;
		initSpeed = 0;
		displayName = "M43 BZ LGB";
		displayNameShort = "M43 BZ LGB";
		descriptionShort = "Laser Guided Cluster Bomb with an chemical gas payload.";
		hardpoints[] = {"I_GBU12","B_GBU12","B_BOMB_PYLON", "B_ASRAAM", "CUP_PylonPod_19Rnd_Rocket_FFAR_plane_M", "DAR","CUP_NATO_HELO_SMALL","CUP_NATO_HELO_LARGE","CUP_NATO_HELO_ROCKETS","CUP_19Rnd_FFAR", "RHS_HP_LONGBOW_RACK", "B_BOMB_FFAR21", "B_BOMB_FFAR7", "FIR_F16_Combined_HP","FIR_F16_AG_HP","FIR_FA18EF_Combined_HP","FIR_A10_BOMB_HP","FIR_AV8B_AG_HP","FIR_SH_AG_HP","FIR_BLUFOR_AG_HP","FIR_BLUFOR_Combined_HP","FIR_FA181E_AG_HP","FIR_F35B_Combined_HP","FIR_FA18_Combined_HP","RHS_HP_FFAR_ARMY","RHS_HP_FFAR_USMC","B_MISSILE_PYLON","B_AGM65_RAIL","I_AGM65_RAIL", "FIR_FA18_Wingtip_HP","FIR_F15E_AA_HP","FIR_F15C_AA_HP","FIR_F15A_AA_HP","FIR_F16_AA_HP","FIR_F16_Combined_HP","FIR_F2A_AA_HP","FIR_F2A_Combined_HP","FIR_BLUFOR_AA_HP","FIR_BLUFOR_Combined_HP", "FIR_F14_SW_LAU138_HP", "FIR_F14_AA_HP", "RHS_HP_INGWE", "RHS_HP_MELB_R", "RHS_HP_MELB","B_AH_99_PYLON","I_BOMB_PYLON","I_MISSILE_PYLON","RHS_HP_B8V20", "pook_SOV_AS18", "POOK_MIG25_CENTERLINE", "CUP_SUPER_PYLON","CUP_EAST_HELO_SMALL","CUP_EAST_HELO_LARGE","CUP_32Rnd_S5", "RHS_HP_INGWE", "RHS_HP_UB32","CUP_O_AA_MISSILE_PYLON","CUP_PylonPod_1Rnd_R73_Vympel", "FIR_OPFOR_Combined_HP","FIR_OPFOR_AG_HP","FIR_Su25_AG_HP","O_BOMB_PYLON","O_MISSILE_PYLON","O_KH25", "RHS_HP_9m120_Mi28", "pook_RPOD", "pook_BMB","pook_HELI_BMB", "pook_HELI_MISSILERACK", "POOK_GUNPOD","CUP_GSh23"};
		mass = 100;
		pylonWeapon = "DIGI_CAS_M43_Bomb";
	};

	class DIGI_CAS_M43_Mag_x2 : PylonRack_Bomb_GBU12_x2 
	{
		ammo = "DIGI_CAS_M43_Ammo";
		author = "DiGii";
		count = 2;
		initSpeed = 0;
		displayName = "2x M43 BZ LGB";
		displayNameShort = "2x M43 BZ LGB";
		descriptionShort = "Laser Guided Cluster Bomb with an chemical gas payload.";
		hardpoints[] = {"I_GBU12","B_GBU12","B_BOMB_PYLON", "B_ASRAAM", "CUP_PylonPod_19Rnd_Rocket_FFAR_plane_M", "DAR","CUP_NATO_HELO_SMALL","CUP_NATO_HELO_LARGE","CUP_NATO_HELO_ROCKETS","CUP_19Rnd_FFAR", "RHS_HP_LONGBOW_RACK", "B_BOMB_FFAR21", "B_BOMB_FFAR7", "FIR_F16_Combined_HP","FIR_F16_AG_HP","FIR_FA18EF_Combined_HP","FIR_A10_BOMB_HP","FIR_AV8B_AG_HP","FIR_SH_AG_HP","FIR_BLUFOR_AG_HP","FIR_BLUFOR_Combined_HP","FIR_FA181E_AG_HP","FIR_F35B_Combined_HP","FIR_FA18_Combined_HP","RHS_HP_FFAR_ARMY","RHS_HP_FFAR_USMC","B_MISSILE_PYLON","B_AGM65_RAIL","I_AGM65_RAIL", "FIR_FA18_Wingtip_HP","FIR_F15E_AA_HP","FIR_F15C_AA_HP","FIR_F15A_AA_HP","FIR_F16_AA_HP","FIR_F16_Combined_HP","FIR_F2A_AA_HP","FIR_F2A_Combined_HP","FIR_BLUFOR_AA_HP","FIR_BLUFOR_Combined_HP", "FIR_F14_SW_LAU138_HP", "FIR_F14_AA_HP", "RHS_HP_INGWE", "RHS_HP_MELB_R", "RHS_HP_MELB","B_AH_99_PYLON","I_BOMB_PYLON","I_MISSILE_PYLON","RHS_HP_B8V20", "pook_SOV_AS18", "POOK_MIG25_CENTERLINE", "CUP_SUPER_PYLON","CUP_EAST_HELO_SMALL","CUP_EAST_HELO_LARGE","CUP_32Rnd_S5", "RHS_HP_INGWE", "RHS_HP_UB32","CUP_O_AA_MISSILE_PYLON","CUP_PylonPod_1Rnd_R73_Vympel", "FIR_OPFOR_Combined_HP","FIR_OPFOR_AG_HP","FIR_Su25_AG_HP","O_BOMB_PYLON","O_MISSILE_PYLON","O_KH25", "RHS_HP_9m120_Mi28", "pook_RPOD", "pook_BMB","pook_HELI_BMB", "pook_HELI_MISSILERACK", "POOK_GUNPOD","CUP_GSh23"};
		mass = 200;
		pylonWeapon = "DIGI_CAS_M43_Bomb";
	};
	

};