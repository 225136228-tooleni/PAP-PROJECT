#ifndef ASSETS_H
#define ASSETS_H
 
/* Asset Management module - MFMS (PAP521S Project A) */
 
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetMenu(void);
 
/* Helpers for the Reports module */
int    getAssetCount(void);
double getTotalAssetValue(void);
 
#endif
 
