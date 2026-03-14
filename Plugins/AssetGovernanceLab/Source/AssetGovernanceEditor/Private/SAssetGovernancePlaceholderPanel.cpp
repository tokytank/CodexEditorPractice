#include "SAssetGovernancePlaceholderPanel.h"

#include "Styling/AppStyle.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SAssetGovernancePlaceholderPanel"

void SAssetGovernancePlaceholderPanel::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(24.0f)
		[
			SNew(SBox)
			.WidthOverride(480.0f)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(LOCTEXT(
					"PlaceholderText",
					"Asset Governance Lab is wired into the editor. The next step is to replace this placeholder with the audit workflow UI."))
			]
		]
	];
}

#undef LOCTEXT_NAMESPACE
