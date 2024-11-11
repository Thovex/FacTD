#include "FacTD_Inspectors.h"

#include <EnTTue/Utils/EntityUtil.h>

#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Editor/EditorEngine.h" // Include this for GEditor

namespace Inspectors::FacTD
{
    TSharedPtr<SBorder> FFacTD_GridComponentInspector::CreateWidget()
    {
        IComponentInspector::CreateWidget();
    
        GridComponent = World->TryGet<FFacTD_GridComponent>(Entity);

        const auto ExpandableArea = SNew(SExpandableArea)
            .InitiallyCollapsed(true)
            .HeaderContent()
            [
                SNew(STextBlock)
                    .Text(FText::FromString(FancyName.ToString()))
            ]
            .BodyContent()
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .AutoHeight()
                [
                    SNew(STextBlock)
                    .Text(FText::FromString(TEXT("Grid Entities")))
                ]
                + SVerticalBox::Slot()
                .AutoHeight()
                [
                    CreateGridEntitiesWidget()
                ]
            ];

        RootWidget->SetContent(ExpandableArea);

        return RootWidget;
    }

    TSharedRef<SWidget> FFacTD_GridComponentInspector::CreateGridEntitiesWidget()
    {
        TSharedRef<SGridPanel> Grid = SNew(SGridPanel);

        if (GridComponent)
        {
            int32 MaxX = 0;
            int32 MaxY = 0;
            for (const auto& Elem : GridComponent->GridEntities)
            {
                if (Elem.Key.X > MaxX) MaxX = Elem.Key.X;
                if (Elem.Key.Y > MaxY) MaxY = Elem.Key.Y;
            }

            for (int32 X = 0; X <= MaxX; ++X)
            {
                for (int32 Y = 0; Y <= MaxY; ++Y)
                {
                    FIntVector Coord(X, Y, 0);
                    FString CoordStr = FString::Printf(TEXT("(%d, %d)"), X, Y);
                    EEntity GridCellEntity = GridComponent->GridEntities.Contains(Coord) 
                        ? EntityUtil::ToEntity(GridComponent->GridEntities[Coord]) 
                        : entt::null;

                    Grid->AddSlot(X, Y)
                    .Padding(1.f)
                    [
                        SNew(SBox)
                        .WidthOverride(100.0f)  // Set uniform width for each cell
                        .HeightOverride(50.0f)  // Set uniform height for each cell
                        [
                            SNew(SBorder)
                            .BorderBackgroundColor(FLinearColor::White)
                            .Padding(5)
                            [
                                SNew(STextBlock)
                                .Text_Lambda([this, GridCellEntity]() {
                                    if (!GEditor || !GEditor->IsPlayingSessionInEditor()) { return FText::FromString(TEXT("[/]")); }
                                    if (!GridComponent) { return FText::GetEmpty(); }
                                    if (!World->Valid(GridCellEntity)) { return FText::FromString(TEXT("Empty")); }

                                    auto& GridCellComp = World->Get<FFacTD_GridCellComponent>(GridCellEntity);
                                    EEntity GridCellOccupant = EntityUtil::ToEntity(GridCellComp.OccupantEntity);
                                    if (World->Valid(GridCellOccupant)) {
                                        return FText::FromString(FString::Printf(TEXT("Occupant: %s"), *World->Get<FNameComponent>(GridCellOccupant).Name.ToString()));
                                    }
                                    return FText::FromString(TEXT("Empty"));
                                })
                                .Justification(ETextJustify::Center)
                                .AutoWrapText(true)  // Enable per-character wrapping
                            ]
                        ]
                    ];
                }
            }
        }
        else
        {
            Grid->AddSlot(0, 0)
            .Padding(1.f)
            [
                SNew(STextBlock)
                .Text(FText::FromString(TEXT("No Grid Component found.")))
            ];
        }

        return SNew(SScrollBox)
            .Orientation(Orient_Horizontal) // Enable horizontal scrolling
            + SScrollBox::Slot()
            [
                SNew(SScrollBox)
                .Orientation(Orient_Vertical) // Enable vertical scrolling
                + SScrollBox::Slot()
                [
                    Grid
                ]
            ];
    }
}
