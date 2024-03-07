//
//  ZegoGameLanguage.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/9.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZegoGameLanguage) {
    // Afrikaans.
    ZegoGameLanguageAF,
    // Amharic.
    ZegoGameLanguageAM,
    // Arabic.
    ZegoGameLanguageAR,
    // Assamese.
    ZegoGameLanguageAS,
    // Azerbaijani.
    ZegoGameLanguageAZ,
    // Bashkir.
    ZegoGameLanguageBA,
    // Belarusian.
    ZegoGameLanguageBE,
    // Bemba language.
    ZegoGameLanguageBEM,
    // Bulgarian.
    ZegoGameLanguageBG,
    // Bislama.
    ZegoGameLanguageBI,
    // Bengali.
    ZegoGameLanguageBN,
    // Tibetan language.
    ZegoGameLanguageBO,
    // Bosnian.
    ZegoGameLanguageBS,
    // Catalan.
    ZegoGameLanguageCA,
    // Cebuano.
    ZegoGameLanguageCEB,
    // Corsican.
    ZegoGameLanguageCO,
    // Seychellois Creole.
    ZegoGameLanguageCRS,
    // Czech.
    ZegoGameLanguageCS,
    // Welsh.
    ZegoGameLanguageCY,
    // Danish.
    ZegoGameLanguageDA,
    // German.
    ZegoGameLanguageDE,
    // Ewe language.
    ZegoGameLanguageEE,
    // Maldivian.
    ZegoGameLanguageDV,
    // Greek.
    ZegoGameLanguageEL,
    // English.
    ZegoGameLanguageEN,
    // Esperanto.
    ZegoGameLanguageEO,
    // Spanish.
    ZegoGameLanguageES,
    // Estonian.
    ZegoGameLanguageET,
    // Basque.
    ZegoGameLanguageEU,
    // Persian.
    ZegoGameLanguageFA,
    // Finnish.
    ZegoGameLanguageFI,
    // Filipino.
    ZegoGameLanguageFIL,
    // Fijian.
    ZegoGameLanguageFJ,
    // Faroese.
    ZegoGameLanguageFO,
    // French.
    ZegoGameLanguageFR,
    // Frisian.
    ZegoGameLanguageFY,
    // Irish.
    ZegoGameLanguageGA,
    // Scottish Gaelic.
    ZegoGameLanguageGD,
   // Galician.
    ZegoGameLanguageGL,
    // Gujarati.
    ZegoGameLanguageGU,
    // Hausa.
    ZegoGameLanguageHA,
    // Hawaiian.
    ZegoGameLanguageHAW,
    // Hebrew.
    ZegoGameLanguageHE,
    // Hindi.
    ZegoGameLanguageHI,
    // Croatian.
    ZegoGameLanguageHR,
    // Upper Sorbian.
    ZegoGameLanguageHSB,
    // Haitian Creole.
    ZegoGameLanguageHT,
    // Hungarian.
    ZegoGameLanguageHU,
    // Armenian.
    ZegoGameLanguageHY,
    // Indonesian.
    ZegoGameLanguageID,
    // Igbo language.
    ZegoGameLanguageIG,
    // Innunaton.
    ZegoGameLanguageIKT,
    // Icelandic.
    ZegoGameLanguageIS,
    // Italian.
    ZegoGameLanguageIT,
    // Inuit language.
    ZegoGameLanguageIU,
    // Japanese.
    ZegoGameLanguageJA,
    // Indonesian Javanese.
    ZegoGameLanguageJV,
    // Georgian.
    ZegoGameLanguageKA,
    // Kekeqi language.
    ZegoGameLanguageKEK,
    // Congolese.
    ZegoGameLanguageKG,
    // Kazakh.
    ZegoGameLanguageKK,
    // Cambodian.
    ZegoGameLanguageKM,
    // Kurdish (North).
    ZegoGameLanguageKMR,
    // Kannada.
    ZegoGameLanguageKN,
    // Korean.
    ZegoGameLanguageKO,
    // Kurdish (central).
    ZegoGameLanguageKU,
    // Kyrgyz.
    ZegoGameLanguageKY,
    // Latin.
    ZegoGameLanguageLA,
    // Luxembourgish.
    ZegoGameLanguageLB,
    // Luganda.
    ZegoGameLanguageLG,
    // Lingala.
    ZegoGameLanguageLN,
    // Lao language.
    ZegoGameLanguageLO,
    // Lithuanian.
    ZegoGameLanguageLT,
    // Latvian.
    ZegoGameLanguageLV,
    // Malagasy.
    ZegoGameLanguageMG,
    // Malian.
    ZegoGameLanguageMHR,
    // Maori.
    ZegoGameLanguageMI,
    // Macedonian.
    ZegoGameLanguageMK,
    // Malayalam.
    ZegoGameLanguageML,
    // Mongolian.
    ZegoGameLanguageMN,
    // Marathi.
    ZegoGameLanguageMR,
    // Mountain Mali.
    ZegoGameLanguageMRJ,
    // Malay.
    ZegoGameLanguageMS,
    // Maltese.
    ZegoGameLanguageMT,
    // Myanmar.
    ZegoGameLanguageMY,
    // Bokmal language.
    ZegoGameLanguageNB,
    // Nepali.
    ZegoGameLanguageNE,
    // Dutch.
    ZegoGameLanguageNL,
    // Norwegian.
    ZegoGameLanguageNO,
    // Chichewa.
    ZegoGameLanguageNY,
    // Oromo language.
    ZegoGameLanguageOM,
    // Oriya.
    ZegoGameLanguageOR,
    // Ossetian.
    ZegoGameLanguageOS,
    // Querétaro Otomi language.
    ZegoGameLanguageOTQ,
    // Punjabi.
    ZegoGameLanguagePA,
    // Papiamento language.
    ZegoGameLanguagePAP,
    // Polish.
    ZegoGameLanguagePL,
    // Dari
    ZegoGameLanguagePRS,
    // Pashto.
    ZegoGameLanguagePS,
    // Portuguese.
    ZegoGameLanguagePT,
    // Lundi language.
    ZegoGameLanguageRN,
    // Romanian.
    ZegoGameLanguageRO,
    // Russian.
    ZegoGameLanguageRU,
    // Kinyarwanda.
    ZegoGameLanguageRW,
    // Sindhi.
    ZegoGameLanguageSD,
    // Sango.
    ZegoGameLanguageSG,
    // Sinhala.
    ZegoGameLanguageSI,
    // Slovak.
    ZegoGameLanguageSK,
    // Slovenian.
    ZegoGameLanguageSL,
    // Samoan.
    ZegoGameLanguageSM,
    // Shona.
    ZegoGameLanguageSN,
    // Somali.
    ZegoGameLanguageSO,
    // Albanian.
    ZegoGameLanguageSQ,
    // Serbian.
    ZegoGameLanguageSR,
    // Sesotho.
    ZegoGameLanguageST,
    // Indonesian Sundanese.
    ZegoGameLanguageSU,
    // Swedish.
    ZegoGameLanguageSV,
    // Swahili.
    ZegoGameLanguageSW,
    // Tamil.
    ZegoGameLanguageTA,
    // Telugu.
    ZegoGameLanguageTE,
    // Tajik.
    ZegoGameLanguageTG,
    // Setswana.
    ZegoGameLanguageTN,
    // Thai.
    ZegoGameLanguageTH,
    // Tigrinya.
    ZegoGameLanguageTI,
    // Tigray.
    ZegoGameLanguageTIG,
    // Turkmen.
    ZegoGameLanguageTK,
    // Klingon.
    ZegoGameLanguageTLH,
    // Tongan.
    ZegoGameLanguageTO,
    // Papuan Pidgin language.
    ZegoGameLanguageTPI,
    // turkish.
    ZegoGameLanguageTR,
    // Tsonga language.
    ZegoGameLanguageTS,
    // Tatar.
    ZegoGameLanguageTT,
    // Twi language.
    ZegoGameLanguageTW,
    // Tahitian.
    ZegoGameLanguageTY,
    // Udmurt language.
    ZegoGameLanguageUDM,
    // Ukrainian.
    ZegoGameLanguageUK,
    // Urdu.
    ZegoGameLanguageUR,
    // Uzbek.
    ZegoGameLanguageUZ,
    // Vietnamese.
    ZegoGameLanguageVI,
    // Warri.
    ZegoGameLanguageWAR,
    // South African Xhosa.
    ZegoGameLanguageXH,
    // Yiddish.
    ZegoGameLanguageYI,
    // Yoruba.
    ZegoGameLanguageYO,
    // Yucatan Mayan.
    ZegoGameLanguageYUA,
    // Cantonese
    ZegoGameLanguageYUE,
    // Simplified Chinese.
    ZegoGameLanguageZHHans,
    // traditional Chinese.
    ZegoGameLanguageZHHant,
    // Zulu.
    ZegoGameLanguageZU
};

/// convert enum to string
static NSString *ZegoGameLanguageMap[] = {
    [ZegoGameLanguageAF] = @"af",
    [ZegoGameLanguageAM] = @"am",
    [ZegoGameLanguageAR] = @"ar",
    [ZegoGameLanguageAS] = @"as",
    [ZegoGameLanguageAZ] = @"az",
    [ZegoGameLanguageBA] = @"ba",
    [ZegoGameLanguageBE] = @"be",
    [ZegoGameLanguageBEM] = @"bem",
    [ZegoGameLanguageBG] = @"bg",
    [ZegoGameLanguageBI] = @"bi",
    [ZegoGameLanguageBN] = @"bn",
    [ZegoGameLanguageBO] = @"bo",
    [ZegoGameLanguageBS] = @"bs",
    [ZegoGameLanguageCA] = @"ca",
    [ZegoGameLanguageCEB] = @"ceb",
    [ZegoGameLanguageCO] = @"co",
    [ZegoGameLanguageCRS] = @"crs",
    [ZegoGameLanguageCS] = @"cs",
    [ZegoGameLanguageCY] = @"cy",
    [ZegoGameLanguageDA] = @"da",
    [ZegoGameLanguageDE] = @"de",
    [ZegoGameLanguageEE] = @"ee",
    [ZegoGameLanguageDV] = @"dv",
    [ZegoGameLanguageEL] = @"el",
    [ZegoGameLanguageEN] = @"en",
    [ZegoGameLanguageEO] = @"eo",
    [ZegoGameLanguageES] = @"es",
    [ZegoGameLanguageET] = @"et",
    [ZegoGameLanguageEU] = @"eu",
    [ZegoGameLanguageFA] = @"fa",
    [ZegoGameLanguageFI] = @"fi",
    [ZegoGameLanguageFIL] = @"fil",
    [ZegoGameLanguageFJ] = @"fj",
    [ZegoGameLanguageFO] = @"fo",
    [ZegoGameLanguageFR] = @"fr",
    [ZegoGameLanguageFY] = @"fy",
    [ZegoGameLanguageGA] = @"ga",
    [ZegoGameLanguageGD] = @"gd",
    [ZegoGameLanguageGL] = @"gl",
    [ZegoGameLanguageGU] = @"gu",
    [ZegoGameLanguageHA] = @"ha",
    [ZegoGameLanguageHAW] = @"haw",
    [ZegoGameLanguageHE] = @"he",
    [ZegoGameLanguageHI] = @"hi",
    [ZegoGameLanguageHR] = @"hr",
    [ZegoGameLanguageHSB] = @"hsb",
    [ZegoGameLanguageHT] = @"ht",
    [ZegoGameLanguageHU] = @"hu",
    [ZegoGameLanguageHY] = @"hy",
    [ZegoGameLanguageID] = @"id",
    [ZegoGameLanguageIG] = @"ig",
    [ZegoGameLanguageIKT] = @"ikt",
    [ZegoGameLanguageIS] = @"is",
    [ZegoGameLanguageIT] = @"it",
    [ZegoGameLanguageIU] = @"iu",
    [ZegoGameLanguageJA] = @"ja",
    [ZegoGameLanguageJV] = @"jv",
    [ZegoGameLanguageKA] = @"ka",
    [ZegoGameLanguageKEK] = @"kek",
    [ZegoGameLanguageKG] = @"kg",
    [ZegoGameLanguageKK] = @"kk",
    [ZegoGameLanguageKM] = @"km",
    [ZegoGameLanguageKMR] = @"kmr",
    [ZegoGameLanguageKN] = @"kn",
    [ZegoGameLanguageKO] = @"ko",
    [ZegoGameLanguageKU] = @"ku",
    [ZegoGameLanguageKY] = @"ky",
    [ZegoGameLanguageLA] = @"la",
    [ZegoGameLanguageLB] = @"lb",
    [ZegoGameLanguageLG] = @"lg",
    [ZegoGameLanguageLN] = @"ln",
    [ZegoGameLanguageLO] = @"lo",
    [ZegoGameLanguageLT] = @"lt",
    [ZegoGameLanguageLV] = @"lv",
    [ZegoGameLanguageMG] = @"mg",
    [ZegoGameLanguageMHR] = @"mhr",
    [ZegoGameLanguageMI] = @"mi",
    [ZegoGameLanguageMK] = @"mk",
    [ZegoGameLanguageML] = @"ml",
    [ZegoGameLanguageMN] = @"mn",
    [ZegoGameLanguageMR] = @"mr",
    [ZegoGameLanguageMRJ] = @"mrj",
    [ZegoGameLanguageMS] = @"ms",
    [ZegoGameLanguageMT] = @"mt",
    [ZegoGameLanguageMY] = @"my",
    [ZegoGameLanguageNB] = @"nb",
    [ZegoGameLanguageNE] = @"ne",
    [ZegoGameLanguageNL] = @"nl",
    [ZegoGameLanguageNO] = @"no",
    [ZegoGameLanguageNY] = @"ny",
    [ZegoGameLanguageOM] = @"om",
    [ZegoGameLanguageOR] = @"or",
    [ZegoGameLanguageOS] = @"os",
    [ZegoGameLanguageOTQ] = @"otq",
    [ZegoGameLanguagePA] = @"pa",
    [ZegoGameLanguagePAP] = @"pap",
    [ZegoGameLanguagePL] = @"pl",
    [ZegoGameLanguagePRS] = @"prs",
    [ZegoGameLanguagePS] = @"ps",
    [ZegoGameLanguagePT] = @"pt",
    [ZegoGameLanguageRN] = @"rn",
    [ZegoGameLanguageRO] = @"ro",
    [ZegoGameLanguageRU] = @"ru",
    [ZegoGameLanguageRW] = @"rw",
    [ZegoGameLanguageSD] = @"sd",
    [ZegoGameLanguageSG] = @"sg",
    [ZegoGameLanguageSI] = @"si",
    [ZegoGameLanguageSK] = @"sk",
    [ZegoGameLanguageSL] = @"sl",
    [ZegoGameLanguageSM] = @"sm",
    [ZegoGameLanguageSN] = @"sn",
    [ZegoGameLanguageSO] = @"so",
    [ZegoGameLanguageSQ] = @"sq",
    [ZegoGameLanguageSR] = @"sr",
    [ZegoGameLanguageST] = @"st",
    [ZegoGameLanguageSU] = @"su",
    [ZegoGameLanguageSV] = @"sv",
    [ZegoGameLanguageSW] = @"sw",
    [ZegoGameLanguageTA] = @"ta",
    [ZegoGameLanguageTE] = @"te",
    [ZegoGameLanguageTG] = @"tg",
    [ZegoGameLanguageTN] = @"tn",
    [ZegoGameLanguageTH] = @"th",
    [ZegoGameLanguageTI] = @"ti",
    [ZegoGameLanguageTIG] = @"tig",
    [ZegoGameLanguageTK] = @"tk",
    [ZegoGameLanguageTLH] = @"tlh",
    [ZegoGameLanguageTO] = @"to",
    [ZegoGameLanguageTPI] = @"tpi",
    [ZegoGameLanguageTR] = @"tr",
    [ZegoGameLanguageTS] = @"ts",
    [ZegoGameLanguageTT] = @"tt",
    [ZegoGameLanguageTW] = @"tw",
    [ZegoGameLanguageTY] = @"ty",
    [ZegoGameLanguageUDM] = @"udm",
    [ZegoGameLanguageUK] = @"uk",
    [ZegoGameLanguageUR] = @"ur",
    [ZegoGameLanguageUZ] = @"uz",
    [ZegoGameLanguageVI] = @"vi",
    [ZegoGameLanguageWAR] = @"war",
    [ZegoGameLanguageXH] = @"xh",
    [ZegoGameLanguageYI] = @"yi",
    [ZegoGameLanguageYO] = @"yo",
    [ZegoGameLanguageYUA] = @"yua",
    [ZegoGameLanguageYUE] = @"yue",
    [ZegoGameLanguageZHHans] = @"zh_CN",
    [ZegoGameLanguageZHHant] = @"zh_TW",
    [ZegoGameLanguageZU] = @"zu",
};
