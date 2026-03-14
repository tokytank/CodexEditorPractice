#pragma once

#include "Widgets/SCompoundWidget.h"

class SAssetGovernancePlaceholderPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAssetGovernancePlaceholderPanel)
	{
	}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
