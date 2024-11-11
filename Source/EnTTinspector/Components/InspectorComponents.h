#pragma once

struct FInspectorInitializedTag {};
struct FInspectorActiveTag {};
struct FInspectorUpdateTag {};

struct FInspectorComponent {

	TSharedPtr<SVerticalBox> Owner = nullptr;
	TSharedPtr<SBorder> RootBorder = nullptr; 	// RootBorder is under Owner
	
	TSharedPtr<SExpandableArea> Root = nullptr;
	
	TSharedPtr<SVerticalBox> InspectorBox = nullptr;
	TSharedPtr<SVerticalBox> TagBox = nullptr;
	TSharedPtr<SVerticalBox> ChildBox = nullptr;
	
	TMap<FName, TSharedPtr<IComponentInspector>> Inspectors = {};
};