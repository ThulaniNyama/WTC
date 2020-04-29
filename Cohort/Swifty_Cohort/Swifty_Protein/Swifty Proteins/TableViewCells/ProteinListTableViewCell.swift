//
//  ProteinListTableViewCell.swift
//  Swifty Proteins
//
//  Created by Sbusiso Xaba on 2019/11/25.
//  Copyright © 2019 sbxaba. All rights reserved.
//

import UIKit

class ProteinListTableViewCell: UITableViewCell {

    @IBOutlet weak var ligandName: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
