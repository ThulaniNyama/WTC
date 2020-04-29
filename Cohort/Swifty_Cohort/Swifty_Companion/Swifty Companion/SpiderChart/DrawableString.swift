//
//  DrawableString.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import Foundation
import UIKit

public protocol DrawableString {
    
    func size() -> CGSize
    func drawDrawable(with rect: CGRect)
    
}

extension NSString: DrawableString {
    
    public func drawDrawable(with rect: CGRect) {
        let style = NSMutableParagraphStyle()
        style.lineBreakMode = .byClipping
        style.alignment = .center
        
        #if swift(>=4.0)
            draw(with: rect, options: .usesLineFragmentOrigin, attributes: [NSAttributedStringKey.paragraphStyle: style], context: nil)
        #else
            draw(with: rect, options: .usesLineFragmentOrigin, attributes: [NSParagraphStyleAttributeName: style], context: nil)
        #endif
    }
    
    public func size() -> CGSize {
        #if swift(>=4.0)
            return size(withAttributes: nil)
        #else
            return size(attributes: nil)
        #endif
    }
    
}

extension String: DrawableString {
    
    public func drawDrawable(with rect: CGRect) {
        (self as NSString).drawDrawable(with: rect)
    }
    
    public func size() -> CGSize {
        return (self as NSString).size()
    }
    
}

extension NSAttributedString: DrawableString {
    
    public func drawDrawable(with rect: CGRect) {
        draw(with: rect, options: .usesLineFragmentOrigin, context: nil)
    }
    
}
